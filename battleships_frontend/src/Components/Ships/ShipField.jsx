import React from "react"


function ShipField(props) {

  return (
    <div id={props.ship + "-" + props.id} />
  );
};

export default ShipField