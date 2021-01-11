export const pBoard = Array.from(Array(100).keys()).map((idx) => {return({id: idx, fieldState: 'empty'})});

export const oBoard = Array.from(Array(100).keys()).map((idx) => {return({id: idx, isChecked: false, fieldState: 'empty'})});

export const shipsArray = [
  {
    id: 4,
    type: "carrier",
    length: 5,
    direction: "horizontal",
  },
  {
    id: 3,
    type: "frigate",
    length: 4,
    direction: "horizontal",
  },
  {
    id: 2,
    type: "destroyer",
    length: 3,
    direction: "horizontal",
  },
  {
    id: 1,
    type: "submarine",
    length: 2,
    direction: "horizontal",
  },
  {
    id: 0,
    type: "patrol",
    length: 1,
    direction: "horizontal",
  }
];