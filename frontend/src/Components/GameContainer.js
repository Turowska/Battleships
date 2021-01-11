import React from "react"
import PlayerBoard from "./PlayerBoard";
import OpponentBorad from "./OpponentBoard"
import DisplayBoard from "./DisplayBoard";
import io from 'socket.io-client'
import { useGlobalContext } from "./context";
import Notifications from "./Notifications";


const convertBoardToBool = (board) => {
  const retv = board.map((field) => { 
    if(field.fieldState === 'empty-field') {
      return false
    } else {
      return true
    }
  })

  return retv;
}

const GameContainer = () => {

  const { playerBoard, socket } = useGlobalContext();

  const joinGame = () => {
    socket.emit('join', convertBoardToBool(playerBoard));
  }

  return (
    <div className="game-container">
      <Notifications />
        <div className="boards-container">
        <DisplayBoard />
        <PlayerBoard/>
        <OpponentBorad/>
        </div>
      <div className="button-container">
      <button className="btn" onClick={joinGame}>
        Play
      </button >
      <button className="btn">
        Reset Board
      </button>
      </div>
    </div>
  );
};


export default GameContainer