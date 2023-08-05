function countup(n) {
  if (n < 1) {
    return [];
  } else {
    const countArray = countup(n - 1);
    countArray.unshift(n);
    return countArray;
  }
}
console.log(countup(5));
