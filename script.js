// Load the WebAssembly module
fetch('output1.wasm')
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.instantiate(bytes, {}))
    .then(result => {
        const instance = result.instance;

        // Function to run the program
        window.runProgram = function() {
            const userInput = document.getElementById('userInput').value;
            const inputPtr = instance.exports.allocateUTF8(userInput);

            // Set the input
            instance.exports.setInput(inputPtr);

            // Get the output
            const outputPtr = instance.exports.getOutput();
            const outputStr = instance.exports.UTF8ToString(outputPtr);

            // Display the output
            document.getElementById('output').textContent = outputStr;

            // Free memory
            instance.exports._free(inputPtr);
            instance.exports._free(outputPtr);
        };
    })
    .catch(err => console.error(err));
