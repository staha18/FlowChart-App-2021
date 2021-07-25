var exec = require('child_process').execFile;

var fun = function () {
    console.log("fun()");
    exec('C:/Users/pesch/Desktop/FlowChart-App/dev/Desktop/Debug/Desktop.exe', function (err, data) {
      console.log(err)
      console.log(data.toString());
    });
  }
  
let gen_process = document.getElementById('btn-gen')
    gen_process.addEventListener('click', function() {
    fun();
    document.querySelector('.btn-one').style.zIndex = "1";
})

const swapIndex = () => {
  document.querySelector('.btn-one').style.zIndex = "-1";
}


function onFileSelected(event) {
  var selectedFile = event.target.files[0];
  var reader = new FileReader();
  reader.onload = function (event) {
    var blob = new Blob([e.target.result], {
      type: "text/plain;charset=utf-8"
    });
    saveAs(blob, "C:/Users/pesch/Desktop/FlowChart-App/dev/Desktop/Desktop/data.txt");
    console.log(blob)
};
  reader.readAsText();
  console.log(reader);

  swapIndex();
}
  
function onFileSelected(event) {
  var file = event.target.files[0];
  var reader = new FileReader();
  reader.onload = function(e) {
    var blob = new Blob([e.target.result], {
      type: "text/plain;charset=utf-8"
    });
    saveAs(blob, "data.txt");
    console.log(e.target.result);
    console.log(blob);
    const link = document.createElement('a')
    link.setAttribute('href', URL.createObjectURL(blob))
    link.setAttribute('download', 'data.txt')
    link.textContent = ''
    document.querySelector('.move-btn').append(link)
    URL.revokeObjectURL(file)
    swapIndex();
  };
  reader.readAsText(file);
}