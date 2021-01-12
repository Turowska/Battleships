import React from "react"

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