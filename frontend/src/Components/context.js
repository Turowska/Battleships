import React, { useContext, useEffect, useState } from 'react'
import { pBoard, shipsArray ,oBoard } from "./data";
import io from 'socket.io-client'


const AppContext = React.createContext();


const AppProvider = ({children}) => {
  const [playerBoard, setPlayerBoard] = useState(pBoard);
  const [opponentBoard, setOpponentBoard] = useState(oBoard);
  const [draggedShip, setDraggedShip] = useState({
    ship : {
      id : -1,
      length: 0,
      direction: ""
    },
    grabbedIdx: 0,
  });
  const [playerNumber, setPlayerNumber] = useState(-1);
  const [socket, setSocket] = useState(null);
  const [socketConnected, setSocketConnected] = useState(false);
  const [playerTurn, setPlayerTurn] = useState(-2);
  const [ships, setShips] = useState(shipsArray);


  useEffect(() => {
    setSocket(io.connect("http://localhost:8000"));
  }, [])

  useEffect(() => {
    if(!socket) return

    socket.on('connect', () => {
      setSocketConnected(true);
      console.log('connected');
    })

    socket.on('disconnect', () => {
      setSocketConnected(false)
      console.log('disconnected');
    })
    
    socket.on('player-disconnected', () => {
      alert("Player disconnected")
    })

    socket.on('player-number', (number) => {
      if(parseInt(number) !== -1) {
        setPlayerNumber(number)
        console.log("Player number is", number);
      }
    })

    socket.on('player-turn', (number) => {
      setPlayerTurn(parseInt(number));
    })

    socket.on('fire', (object) => {
      const {hit, field} = object;
      const newState = hit ? "taken hit" : "missed";
      let newPlayerBoard = [...playerBoard];
      newPlayerBoard[field].fieldState = newState;
      setPlayerBoard(newPlayerBoard);
    })

    socket.on('game-over', () => {
      alert("GameOVER you have won!")
      setPlayerNumber(-1);
      resetBoard();
    })

  }, [socket])

  const resetBoard = () => {
    setPlayerBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, fieldState: 'empty'})}));
    setOpponentBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, isChecked: false, fieldState: 'empty'})}));
    setShips(shipsArray);
  }

  return <AppContext.Provider 
  value={{ 
      playerBoard,  
      setPlayerBoard,
      opponentBoard,
      setOpponentBoard,
      draggedShip,
      resetBoard,
      setDraggedShip,
      playerNumber,
      playerTurn,
      socket,
      ships,
      setShips
    }}>
    {children}
  </AppContext.Provider>
}

export const useGlobalContext = () => {
  return useContext(AppContext);
}

export {AppContext, AppProvider}