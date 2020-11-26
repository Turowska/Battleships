import React from "react"
import Field from "./Field";

function Board(props) {
  return (
    <div className={"board " + props.user + "-board"}>
      {Array.from(Array(100).keys()).map(idx => <Field key={idx} type="emptyField" id={idx} />)}
    </div>
  );
};

export default Board