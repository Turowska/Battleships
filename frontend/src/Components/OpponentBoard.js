import React, { useState } from "react"
import { useGlobalContext } from "./context";
import OpponentField from "./OpponentField";

const OpponentBoard = () => {
  const {opponentBoard, chagneOpponentBoard, playerTurn, playerNumber, socket } = useGlobalContext();

  const onClick = (e) => {
    const markedField = parseInt(e.target.id);
    if(markedField < 100 && playerTurn === playerNumber && !opponentBoard[markedField].isChecked) {
      socket.emit('shoot', { field: markedField }, (isHit) => {
        const newState = isHit ? "hit" : "missed";
        let newOpponentBoard = [...opponentBoard];
        newOpponentBoard[markedField].fieldState = newState;
        newOpponentBoard[markedField].isChecked = true;
        chagneOpponentBoard(newOpponentBoard);
      })      
    } 
  }


  return (
    <div 
      className={"board"}
      onClick={onClick}
    >
      {Array.from(Array(100).keys()).map(idx => <OpponentField key={idx} field={opponentBoard[idx]}/>)}
    </div>
  );
};

export default OpponentBoard;