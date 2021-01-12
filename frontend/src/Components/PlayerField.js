import React from "react"

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