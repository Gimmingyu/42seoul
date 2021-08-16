const month = 7;
let day = 13;

const timeWarp = (newMonth, newDay) => {
  if (month > 0 && month < 13) {
    month.month = newMonth;
    const m_d = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    if (newDay > 0 && newDay < m_d[newMonth - 1] + 1) {
      day = newDay;
      console.log(`Current time: ` + month.month + `-` + `${day}`);
    }
    else {
      console.log(`Error! Input valid day`);
    }
  }
  else {
    console.log(`Error! Input valid month`);
  }
}
