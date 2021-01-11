import React from "react"
import { useGlobalContext } from "../context";


const ShipField = ({id, type}) => {
  const {draggedShip, setDraggedShip} = useGlobalContext();

  const onMouseDown = (e) => {
    const newDraggedShip = {...draggedShip, grabbedIdx: e.target.id};
    setDraggedShip(newDraggedShip);
  }

  return (
    <div 
      id={id} 
      type={type}
      onMouseDown={onMouseDown}
    />
  );
};

export default ShipField