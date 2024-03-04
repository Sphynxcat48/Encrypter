// Load the WebAssembly module
const Module = {
    onRuntimeInitialized: function() {
        console.log("WASM module loaded");
    }
};

fetch('output.wasm')
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.instantiate(bytes, Module))
    .then(instance => {
        // Set the input
        const setInput = instance.exports.setInput;
        const inputStr = "your_input_string_here";
        const inputPtr = Module._malloc(inputStr.length + 1);
        Module.stringToUTF8(inputStr, inputPtr, inputStr.length + 1);
        setInput(inputPtr);

        // Get the output
        const getOutput = instance.exports.getOutput;
        const outputPtr = getOutput();
        const outputStr = Module.UTF8ToString(outputPtr);

        // Use the output
        console.log("Output:", outputStr);

        // Free memory
        Module._free(inputPtr);
        Module._free(outputPtr);
    });
