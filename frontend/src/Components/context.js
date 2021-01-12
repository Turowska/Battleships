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
  const [playerTurn, setPlayerTurn] = useState(-2);
  const [ships, setShips] = useState(shipsArray);

  const resetBoard = () => {
    setPlayerBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, fieldState: 'empty'})}));
    setOpponentBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, isChecked: false, fieldState: 'empty'})}));
    setShips(shipsArray);
  }


  useEffect(() => {
    setSocket(io.connect("http://localhost:8000"));
  }, [])

  useEffect(() => {
    if(!socket) return

    socket.on('connect', () => {
      console.log('connected');
    });

    socket.on('disconnect', () => {
      console.log('disconnected');
    });

    socket.on('player-number', (number) => {
      if(parseInt(number) !== -1) {
        setPlayerNumber(number)
      }
    });

    socket.on('player-turn', (number) => {
      setPlayerTurn(parseInt(number));
    });

    socket.on('bad-board', () => {
      alert("One of the players connected with faulty board!");
      setPlayerNumber(-1);
      setPlayerTurn(-2);
      resetBoard();
    });

    socket.on('fire', (object) => {
      const {hit, field} = object;
      const newState = hit ? "taken hit" : "missed";
      let newPlayerBoard = [...playerBoard];
      newPlayerBoard[field].fieldState = newState;
      setPlayerBoard(newPlayerBoard);
    });

    socket.on('game-over-win', () => {
      setPlayerBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, fieldState: 'empty'})}));
      setOpponentBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, isChecked: false, fieldState: 'empty'})}));
      setShips(shipsArray);
      setPlayerTurn(-2);
      setPlayerNumber(-1);
      alert("Game over you've won!");
    });

    socket.on('game-over-left', () => {
      setPlayerBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, fieldState: 'empty'})}));
      setOpponentBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, isChecked: false, fieldState: 'empty'})}));
      setShips(shipsArray);
      setPlayerTurn(-2);
      setPlayerNumber(-1);
      alert("Game over opponent has left the game!");
    });

    socket.on('isHit', ({hit, field}) => {
      const newState = hit ? "hit" : "missed";
      let newOpponentBoard = [...opponentBoard];
      newOpponentBoard[field].fieldState = newState;
      newOpponentBoard[field].isChecked = true;
      setOpponentBoard(newOpponentBoard);
    });

    socket.on('game-over-lost', () => {
      setPlayerBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, fieldState: 'empty'})}));
      setOpponentBoard(Array.from(Array(100).keys()).map((idx) => {return({id: idx, isChecked: false, fieldState: 'empty'})}));
      setShips(shipsArray);
      setPlayerTurn(-2);
      setPlayerNumber(-1);
      alert("Game over you've lost");
    });

    socket.on('sunked', (sunkedShip) => {
      let newOppoenentBoard = [...opponentBoard];
      sunkedShip.map((sunkedIdx) => {
        newOppoenentBoard[sunkedIdx].fieldState = "taken hit"
      })
      setOpponentBoard(newOppoenentBoard);
    });

  }, [socket])

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
      setShips,
    }}>
    {children}
  </AppContext.Provider>
}

export const useGlobalContext = () => {
  return useContext(AppContext);
}

export {AppContext, AppProvider}