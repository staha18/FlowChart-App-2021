var exec = require('child_process').execFile;

var fun = function () {
    console.log("fun()");
    exec('C:/dev/Desktop/Debug/Desktop.exe', function (err, data) {
      console.log(err)
      console.log(data.toString());
    });
  }

const gen_process = document.getElementById('btn-gen')
    gen_process.addEventListener('click', function() {
    fun();
    document.querySelector('.btn-one').style.zIndex = "1";
})

const onFileSelected = () => {
  swapIndex();
}

const swapIndex = () => {
  document.querySelector('.btn-one').style.zIndex = "-2";
}