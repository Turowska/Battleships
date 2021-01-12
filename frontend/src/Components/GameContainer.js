import React from "react"
import PlayerBoard from "./PlayerBoard";
import OpponentBorad from "./OpponentBoard"
import DisplayBoard from "./DisplayBoard";
import { useGlobalContext } from "./context";
import Notifications from "./Notifications";


const convertBoardToBool = (board) => {
  const retv = board.map((field) => { 
    if(field.fieldState === 'empty') {
      return false
    } else {
      return true
    }
  })

  return retv;
}

const isBoardCorrect = (board) => {
  var counter = 0;
  for(var i = 0; i < board.length; i++) {
    if(board[i] === true) {
      counter++;
    }
  }

  if(counter === 15) {
    return true
  } else {
    return false
  }
}

const GameContainer = () => {

  const { playerNumber, playerBoard, resetBoard, socket } = useGlobalContext();

  const joinGame = () => {
    if(isBoardCorrect(convertBoardToBool(playerBoard))) { 
      socket.emit('join', convertBoardToBool(playerBoard));
    } else {
      resetBoard();
    } 
  }


  return (
    <div className="game-container">
      <Notifications />
        <div className="boards-container">
        <PlayerBoard/>
        <OpponentBorad/>
        </div>
      <div className="button-container">
      {playerNumber === -1 && <button className="btn" onClick={joinGame}>Play</button >}
      {playerNumber === -1 && <button className="btn" onClick={() => {resetBoard()}}>Reset Board</button>}
      </div>
      <DisplayBoard />
    </div>
  );
};


export default GameContainer