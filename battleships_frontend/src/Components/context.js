import React, { useContext, useEffect, useState } from 'react'
import { pBoard, oBoard } from "./data";
import io from 'socket.io-client'


const AppContext = React.createContext();


const AppProvider = ({children}) => {
  const [playerBoard, setPlayerBoard] = useState(pBoard);
  const [opponentBoard, setOpponentBoard] = useState(oBoard);
  const [draggedShip, setDraggedShip] = useState({
    type: "",
    direction: "",
    length: 0,
    grabbedIdx: 0,
  });
  const [playerNumber, setPlayerNumber] = useState(-1);
  const [socket, setSocket] = useState(null);
  const [socketConnected, setSocketConnected] = useState(false)


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

  }, [socket])


  const changePlayerBoard = (newBoard) => {
    setPlayerBoard(newBoard);
  }
  
  const chagneOpponentBoard = (newBoard) => {
    setOpponentBoard(newBoard);
  }

  return <AppContext.Provider 
  value={{ 
      playerBoard,  
      changePlayerBoard,
      opponentBoard,
      chagneOpponentBoard,
      draggedShip,
      setDraggedShip,
      playerNumber,
      socket
    }}>
    {children}
  </AppContext.Provider>
}

export const useGlobalContext = () => {
  return useContext(AppContext);
}

export {AppContext, AppProvider}