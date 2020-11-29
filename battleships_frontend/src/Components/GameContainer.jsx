import React from "react"
import Board from "./Board";
import Borad from "./Board"
import DisplayBoard from "./DisplayBoard";
import Notifications from "./Notifications"

function GameContainer() {
  return (
    <div className="game-container">
      <DisplayBoard />
      <Board user="player" />
      <Board user="opponent" />
      <button>Play</button>
    </div>
  );
};


export default GameContainer