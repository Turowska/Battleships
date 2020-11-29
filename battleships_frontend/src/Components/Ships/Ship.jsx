import React, { useState } from "react"
import ShipField from "./ShipField";

function shipLength(shipName) {
  let shipLength;
  switch (shipName) {
    case "carrier":
      shipLength = 5;
      break;
    case "frigate":
      shipLength = 4;
      break;
    case "destroyer":
      shipLength = 3;
      break;
    case "submarine":
      shipLength = 2;
      break;
    case "patrol":
      shipLength = 1;
      break;
    default:
      shipLength = 0;
  }
  return shipLength;
}

function Ship(props) {
  const [direction, changeDireciton] = useState("horizontal");


  const rotate = e => {
    const newDirection = direction === "horizontal" ? "vertical" : "horizontal";
    changeDireciton(newDirection);
  }


  const onDragStart = e => {
    const target = e.target;
    e.dataTransfer.setData("ship-id", target.id);

    console.log(target);
  }

  const dragOver = e => {
    e.preventDefault();
  }

  const shipName = props.ship;
  let length = shipLength(shipName);

  return (
    <div
      className={"ship " + shipName + "-" + direction}
      onDoubleClick={rotate}
      draggable="true"
      onDragOver={dragOver}
      onDragStart={onDragStart}
    >
      {Array.from(Array(length).keys()).map(idx => <ShipField key={idx} ship={shipName} id={idx} />)}
    </div>
  );
};

export default Ship