import React from "react"
import Ship from "./Ships/Ship"

const DisplayBoard = () => {

  return (
    <div className="board display-board">
      {Array.from(Array(5).keys()).map((idx) => <Ship key={idx} id={idx} />)}
    </div>
  );
};

export default DisplayBoard