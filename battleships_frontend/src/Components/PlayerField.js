import React, { useState } from "react"
import { useGlobalContext } from "./context";

const PlayerField = ({field}) => {
  
  const {id, fieldState} = field;
  
  return (
    <div 
      id={id} 
      className={fieldState}
    />
  );
};

export default PlayerField