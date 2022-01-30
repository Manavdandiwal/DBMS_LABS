let numbers = [0];
const inputBox = document.querySelector('.input-area');

function updateInput(value){
    inputBox.textContent = value;
}

const allButtons = document.querySelectorAll('.buttons');
const numericButtons = document.querySelectorAll('.numeral');
const operationButtons = document.querySelectorAll('.operation');
const operation = [];
const numerals = [];
for (let i = 0; i < operationButtons.length; i++)
{
    operation.push(operationButtons[i].innerText);
}

for (let i = 0; i < numericButtons.length; i++)
{
    numerals.push(numericButtons[i].innerText);
}

let text = "";
let currentOperation = "";
for (let i = 0; i < allButtons.length; i++)
{
    allButtons[i].addEventListener('click', function(){
        text = allButtons[i].innerText;

        if (text === "C")
        {
            while (numbers.length)
                numbers.pop();
            numbers.push(0);
            updateInput(0);
        }

        else if (text in numerals === true)
        {
            let num = numbers[numbers.length - 1];
            numbers.pop();
            num *= 10;
            num += parseInt(text);
            numbers.push(num);
        }

        else if (text === '<<')
        {
            let length = numbers.length;
            let val = numbers[length - 1];
            val = Math.floor(val / 10);
            numbers.pop();
            numbers.push(val);
        }

        else
        {
            if (text === '=')
            {
                let val = performOperation(numbers, currentOperation);
                while (numbers.length != 0)
                    numbers.pop();
                numbers.push(val);
            }

            else
            {
                if (numbers.length > 1)
                {
                    let val = performOperation(numbers, currentOperation);
                    while (numbers.length != 0)
                        numbers.pop();
                    numbers.push(val);
                }
                currentOperation = text;
                numbers.push(0);
                console.log(numbers);
            }
        }
        updateInput(numbers[numbers.length - 1]);
    });
}

function performOperation(numbers, op)
{
    if (op === '+')
        return numbers[0] + numbers[1];

    else if (op === '-')
        return numbers[0] - numbers[1];

    else if (op === '*')
        return numbers[0] * numbers[1];

    else if (op === '/')
        return numbers[0] / numbers[1];
}
