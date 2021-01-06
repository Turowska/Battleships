import React, { useContext, useState } from 'react'
import { pBoard, ships, oBoard } from "./data";

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
      setDraggedShip
    }}>
    {children}
  </AppContext.Provider>
}

export const useGlobalContext = () => {
  return useContext(AppContext);
}

export {AppContext, AppProvider}