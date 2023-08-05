
function countdown(n){
  if(n < 1  || n > 20){
    return [];
  }
  else{
    var count = countdown(n + 1);
    if (n > 10) { count.push(n - 10); }
    return count;
  }
}

console.log(countdown(10));