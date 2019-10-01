//search largest value after product of adjcent array el
console.time("cont");
function pro(arr) {

  var new_arr = [];

  for (let i = 0; i < arr.length - 1; i++) {
    new_arr[i] = arr[i] * arr[i + 1];
  }

  var l = new_arr[0];

  for (let j = 0; j < new_arr.length - 1; j++) {
    if (l > new_arr[j + 1]) {
      l;

    } else {
      l = new_arr[j + 1];

    }
  }
  console.log(l);
}
console.timeEnd("cont");
pro([-23, 4, -3, 8, -12]);
//pro([1, 0, 1, 0, 1000]);

//git remote add origin https://github.com/codernuub/codernuub-Hacktober.git
//git push origin master


