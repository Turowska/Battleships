import React from "react"
import { useGlobalContext } from "./context";
import PlayerField from "./PlayerField";

const width = 10;

const validatePlacementHorizontally = (dropped, draggedShip) => {
  let droppedWidth = dropped % 10;
  if(droppedWidth + draggedShip.ship.length - draggedShip.grabbedIdx < 10 && droppedWidth + draggedShip.ship.length - draggedShip.grabbedIdx >= draggedShip.ship.length) {
    return true
  } else {
    return false
  }
};

const validatePlacementVertically = (dropped, draggedShip) => {
  let droppedHeight = Math.floor(parseInt(dropped)/10);
  if(droppedHeight + draggedShip.ship.length - draggedShip.grabbedIdx < 10 && droppedHeight + draggedShip.ship.length - draggedShip.grabbedIdx >= draggedShip.ship.length) {
    return true
  } else {
    return false
  }
};

const PlayerBoard = () => {

  const {playerBoard, changePlayerBoard, draggedShip, ships, setShips} = useGlobalContext();

  const onDrop = e => {
    e.preventDefault();
    const dropped = e.target.id;
    let newPlayerBoard = [...playerBoard];

    if(draggedShip.ship.direction == 'horizontal') {
      if(validatePlacementHorizontally(dropped, draggedShip)) {
        for (let index = 0; index <= draggedShip.ship.length; index++) {
          const idx  = parseInt(dropped) + parseInt(index) - parseInt(draggedShip.grabbedIdx);
          newPlayerBoard[idx].fieldState = "ship " + draggedShip.ship.type + "-field";          
        }
        changePlayerBoard(newPlayerBoard);
        const newShips = ships.filter(ship => ship.id !== draggedShip.ship.id);
        setShips(newShips);
      }
    } else {
      if(validatePlacementVertically(dropped, draggedShip)) {
        for (let index = 0; index <= draggedShip.ship.length; index++) {
          const idx = parseInt(dropped) + parseInt(index) * 10 - parseInt(draggedShip.grabbedIdx) * 10;
          newPlayerBoard[idx].fieldState = "ship " + draggedShip.ship.type + "-field";
        }
        changePlayerBoard(newPlayerBoard);
        const newShips = ships.filter(ship => ship.id !== draggedShip.ship.id);
        setShips(newShips);
      }
    }
  }

  const dragOver = e => {
    e.preventDefault();
  }
  
  const onDragLeave = e => {
    e.preventDefault();
  }

  return (
    <div
      className={"board"}
      onDrop={onDrop}
      onDragOver={dragOver}
      onDragLeave={onDragLeave}
    >
      {Array.from(Array(100).keys()).map(idx => <PlayerField key={idx} field={playerBoard[idx]}/>)}
    </div>
  );
};

export default PlayerBoard