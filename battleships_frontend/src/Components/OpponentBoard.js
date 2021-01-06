import React, { useState } from "react"
import { useGlobalContext } from "./context";
import OpponentField from "./OpponentField";

const OpponentBoard = () => {
  const {opponentBoard, chagneOpponentBoard } = useGlobalContext();

  const onClick = (e) => {
    const markedField = parseInt(e.target.id);
    console.log("clicked field " + markedField);
    if(markedField < 100) {
      const newStyle = opponentBoard[markedField].isOccupied === "empty" ? "missed" : "hit";
      let newOpponentBoard = opponentBoard;
      newOpponentBoard[markedField].fieldState = newStyle;
      newOpponentBoard[markedField].isChecked = true;
      chagneOpponentBoard(newOpponentBoard);
    } 
  }


  return (
    <div 
      className={"board opponent-board"}
      onClick={onClick}
    >
      {Array.from(Array(100).keys()).map(idx => <OpponentField key={idx} field={opponentBoard[idx]}/>)}
    </div>
  );
};

export default OpponentBoard;