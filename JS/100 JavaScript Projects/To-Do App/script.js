const addToDoBtn = document.getElementById("button-addon2");
const toDoContainer = document.getElementById("toDoContainer");
const inputField = document.getElementById("inputField");

let todos = [];

const storedData = localStorage.getItem("todos");
if (storedData) {
  todos = JSON.parse(storedData);
  todos.forEach(createToDoRow);
}

addToDoBtn.addEventListener("click", function (e) {
  // for each todo we create an todoObj
  const toDoObj = {
    id: Math.floor(Date.now() * Math.random()),
    taskName: inputField.value,
    completed: false,
  };
  todos.push(toDoObj);
  createToDoRow(toDoObj);
  // saving todos in local storage
  saveToDos();
  inputField.value = "";
});

function createToDoRow(toDoObj) {
  const row = document.createElement("tr");
  row.id = `toDo${toDoObj.id}`;
  row.innerHTML = `
    <td id='taskName${toDoObj.id}' class="fs-3">${toDoObj.taskName}</td>
    <td>
      <div class="form-check">
        <input
          class="form-check-input mx-auto d-block check${toDoObj.id}"
          type="checkbox"
          value=""
          id="flexCheckDefault${toDoObj.id}"
          
        />
      </div>
    </td>
    <td>
      <button type="button" class="btn btn-danger" id="btn${toDoObj.id}">delete</button>
    </td>
    `;
  toDoContainer.appendChild(row);
  markAsCompleted(toDoObj);
  removeTask(toDoObj);
}

function markAsCompleted(toDoObj) {
  const completedCheckBox = document.querySelector(`.check${toDoObj.id}`);
  const taskName = document.getElementById(`taskName${toDoObj.id}`);
  // sync check box with completed property in toDoObj in the beginning
  completedCheckBox.checked = toDoObj.completed;
  styleAsCompleted(taskName, completedCheckBox);
  completedCheckBox.addEventListener("change", function () {
    toDoObj.completed = completedCheckBox.checked;
    styleAsCompleted(taskName, completedCheckBox);
    saveToDos();
  });
}

function removeTask(toDoObj) {
  const deleteBtn = document.querySelector(`#btn${toDoObj.id}`);
  const taskToRemove = document.querySelector(`#toDo${toDoObj.id}`);
  deleteBtn.addEventListener("click", function () {
    taskToRemove.remove();
    todos.splice(
      todos.findIndex((item) => item.id === toDoObj.id),
      1
    );
    saveToDos();
  });
}
function styleAsCompleted(taskName, completedCheckBox) {
  taskName.style.textDecoration = completedCheckBox.checked
    ? "line-through"
    : "none";
  completedCheckBox.checked
    ? taskName.classList.add("lead", "text-white-50")
    : taskName.classList.remove("lead", "text-white-50");
}

function saveToDos() {
  localStorage.setItem("todos", JSON.stringify(todos));
}
