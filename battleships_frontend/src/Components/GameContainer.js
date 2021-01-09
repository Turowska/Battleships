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
      return true
    } else {
      return false
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
      {/* <Notifications /> */}
      <DisplayBoard />
      <PlayerBoard/>
      <OpponentBorad/>
      <button className="btn" onClick={joinGame}>
        Play
      </button >
      {/* <button className="btn">
        Reset Board
      </button> */}
    </div>
  );
};


export default GameContainer