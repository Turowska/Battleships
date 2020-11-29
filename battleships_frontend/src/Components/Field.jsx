import React, { Component, useState } from "react"

function Field(props) {
  return (
    <div className={props.type} id={props.id} />
  );
};

export default Field