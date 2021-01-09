import React, {useState} from "react"
import { useGlobalContext } from "../context";
import { ships } from "../data";
import ShipField from "./ShipField";


const Ship = ({id}) => {

  const {draggedShip, setDraggedShip} = useGlobalContext();

  const [direction, setDirection] = useState('horizontal')
  const type = ships[id].type;
  const length = ships[id].length;

  const rotate = () => {
    const newDirection = direction === "horizontal" ? "vertical" : "horizontal";
    setDirection(newDirection);
  }

  const onDragStart = e => {
    const newDraggedShip = {...draggedShip, type: type, length: length - 1, direction: direction}
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