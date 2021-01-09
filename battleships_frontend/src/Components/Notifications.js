import React from "react"
import { useGlobalContext } from "./context";

const Notifications = () => {
  const { playerNumber } = useGlobalContext();

  if(playerNumber === -1) {
    return (
      <div className="notifications">
        <span className="">
          <p>Set Up your board and press play to connect to game room</p>
        </span>
      </div>
    );
  }

  return (
    <div className="notifications">
      <span className="">
        <p>Waiting for another player to connect</p>
      </span>
    </div>
  );
};

export default Notifications