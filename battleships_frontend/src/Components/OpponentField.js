import React, { useState } from "react"
import { useGlobalContext } from "./context";

const OpponentField = ({field}) => {
  
  const {id, fieldState} = field;
  
  return (
    <div 
      id={id} 
      className={fieldState}
    />
  );
};

export default OpponentField