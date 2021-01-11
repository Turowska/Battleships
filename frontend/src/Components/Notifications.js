import React from "react"
import { useGlobalContext } from "./context";

const Notifications = () => {
  const { playerNumber, playerTurn } = useGlobalContext();

  if(playerNumber === -1) {
    return (
      <div className="notifications">
        <span>
          Set Up your board and press play to connect to game room
        </span>
      </div>
    );
  }

  if(playerTurn === -2) {
    return (
      <div className="notifications">
        <span>
          Waiting for another player to connect
        </span>
      </div>
    );
  }

  if(playerNumber === playerTurn) {
    return (
      <div className="notifications">
        <span>
          Your Turn to shoot
        </span>
      </div>
    );
  } else {
    return (
      <div className="notifications">
        <span>
          Enemy's turn to shoot
        </span>
      </div>
    );
  }
  

 
};

export default Notifications