import React, { Component } from "react"

function Field(props) {
  let className;
  switch (props.type) {
    case "emptyField":
      className = "empty-field";
      break;
  };

  return (
    <div className={className} />
  );
};

export default Field