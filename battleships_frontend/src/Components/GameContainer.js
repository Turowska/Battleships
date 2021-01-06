import React from "react"
import PlayerBoard from "./PlayerBoard";
import OpponentBorad from "./OpponentBoard"
import DisplayBoard from "./DisplayBoard";
import Notifications from "./Notifications"

const GameContainer = () => {

  return (
    <div className="game-container">
      <DisplayBoard />
      <PlayerBoard />
      <OpponentBorad/>
      <button>Play</button>
    </div>
  );
};


export default GameContainer