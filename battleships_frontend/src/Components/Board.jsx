import React, { useState } from "react"
import Field from "./Field";

const initialState = Array.from(Array(100).keys()).map(() => "empty-field")

function Board(props) {
  const [boardState, changeBoardState] = useState(initialState)

  const onDrop = e => {
    e.preventDefault();
    const field = e.dataTransfer.getData('ship-id');

    const ship = document.getElementById(field);
    // ship.style.display = 'block';


  }

  const dragOver = e => {
    e.preventDefault();
  }

  return (
    <div
      className={"board " + props.user + "-board"}
      onDrop={onDrop}
      onDragOver={dragOver}
    >
      {Array.from(Array(100).keys()).map(idx => <Field key={idx} type={boardState[idx]} id={idx} />)}
    </div>
  );
};

export default Board