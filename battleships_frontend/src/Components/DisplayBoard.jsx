import React from "react"
import Ship from "./Ships/Ship"

function DisplayBoard(props) {
  return (
    <div className="board display-board">
      <Ship ship="patrol" />
      <Ship ship="submarine" />
      <Ship ship="destroyer" />
      <Ship ship="frigate" />
      <Ship ship="carrier" />

    </div>
  );
};

export default DisplayBoard