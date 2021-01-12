import React, {useState} from "react"
import { useGlobalContext } from "../context";
import { ships } from "../data";
import ShipField from "./ShipField";


const Ship = ({ship}) => {

  const {draggedShip, setDraggedShip, ships ,setShips} = useGlobalContext();

  const { id, type, length, direction} = ship

  const rotate = () => {
    const newDirection = direction === "horizontal" ? "vertical" : "horizontal";
    const newShips = ships.map((ship) => {
      if(ship.id === id) {
        return {id, type, length, direction: newDirection}
      } else {
        return ship
      }
    })
    setShips(newShips);
  }

  const onDragStart = e => {
    const newDraggedShip = {...draggedShip, ship: { id, type, length: length - 1, direction}}
    setDraggedShip(newDraggedShip);
  }

  const dragOver = e => {
    e.preventDefault();
  }

  return (
    <div
      className={"ship " + type + "-" + direction}
      draggable="true"
      onDoubleClick={rotate}
      onDragOver={dragOver}
      onDragStart={onDragStart}
    >
      {Array.from(Array(length).keys()).map(idx => <ShipField key={idx} id={idx} type={type} />)}
    </div>
  );
};

export default Ship