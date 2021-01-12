import React from "react"
import { useGlobalContext } from "./context";
import Ship from "./Ships/Ship"

const DisplayBoard = () => {

  const {ships} = useGlobalContext();

  return (
    <div className="display-board">
      {ships.map((ship) => <Ship key={ship.id} ship={ship} />)}
    </div>
  );
};

export default DisplayBoard