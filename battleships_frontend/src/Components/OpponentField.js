import React, { useState } from "react"
import { useGlobalContext } from "./context";

const OpponentField = ({field}) => {
  
  const {id, isChecked, isOccupied} = field;

  let fieldStyle;

  if(!isChecked) {
    fieldStyle = 'empty-field'
  } else {
    fieldStyle = isOccupied === "empty" ? 'missed' : "hit";
  }

  
  return (
    <div 
      id={id} 
      className={fieldStyle}
    />
  );
};

export default OpponentField