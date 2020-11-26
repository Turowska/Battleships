import React from "react"
import ShipField from "./ShipField";

function Ship(props) {
  const shipName = props.ship;
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

  return (
    <div className={"ship " + shipName}>
      {Array.from(Array(shipLength).keys()).map(idx => <ShipField key={idx} ship={shipName} id={idx} />)}
    </div>
  );
};

export default Ship