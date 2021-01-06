import React from "react"
import { useGlobalContext } from "./context";
import PlayerField from "./PlayerField";

const width = 10;

const validatePlacementHorizontally = (dropped, ship) => {
  let droppedWidth = dropped % 10;
  if(droppedWidth + ship.length - ship.grabbedIdx < 10 && droppedWidth + ship.length - ship.grabbedIdx >= ship.length) {
    return true
  } else {
    return false
  }
};

const validatePlacementVertically = (dropped, ship) => {
  let droppedHeight = Math.floor(parseInt(dropped)/10);
  if(droppedHeight + ship.length - ship.grabbedIdx < 10 && droppedHeight + ship.length - ship.grabbedIdx >= ship.length) {
    return true
  } else {
    return false
  }
};

const PlayerBoard = () => {

  const {playerBoard, changePlayerBoard, draggedShip} = useGlobalContext();

  const onDrop = e => {
    e.preventDefault();
    const dropped = e.target.id;
    let newPlayerBoard = [...playerBoard];    
    if(draggedShip.direction == 'horizontal') {
      if(validatePlacementHorizontally(dropped, draggedShip)) {
        for (let index = 0; index <= draggedShip.length; index++) {
          const idx  = parseInt(dropped) + parseInt(index) - parseInt(draggedShip.grabbedIdx);
          newPlayerBoard[idx].fieldState = "ship " + draggedShip.type + "-field";          
        }
        changePlayerBoard(newPlayerBoard);
      }
    } else {
      if(validatePlacementVertically(dropped, draggedShip)) {
        for (let index = 0; index <= draggedShip.length; index++) {
          const idx = parseInt(dropped) + parseInt(index) * 10 - parseInt(draggedShip.grabbedIdx) * 10;
          console.log(idx);
          newPlayerBoard[idx].fieldState = "ship " + draggedShip.type + "-field";
        }
        changePlayerBoard(newPlayerBoard);
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
      className={"board player-board"}
      onDrop={onDrop}
      onDragOver={dragOver}
      onDragLeave={onDragLeave}
    >
      {Array.from(Array(100).keys()).map(idx => <PlayerField key={idx} field={playerBoard[idx]}/>)}
    </div>
  );
};

export default PlayerBoard