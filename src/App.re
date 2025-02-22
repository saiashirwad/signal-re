type todo = {
  id: int,
  title: string,
  completed: bool,
};

type state = {
  todos: list(todo),
  input: string,
};

type action =
  | AddTodo(string)
  | ToggleTodo(int)
  | RemoveTodo(int)
  | ClearCompleted
  | SetInput(string)
  | ClearInput;

let initialState = {
  todos: [],
  input: "",
};

module App = {
  [@react.component]
  let make = () => {
    let (state, dispatch) =
      React.useReducer(
        (state, action) =>
          switch (action) {
          | _ => state
          },
        initialState,
      );

    <div>
      <input
        value={state.input}
        onChange={e => dispatch(SetInput(RR.getValueFromEvent(e)))}
      />
      <button onClick={_ => dispatch(AddTodo(state.input))}>
        {React.string("Add")}
      </button>
      <div> {React.string("Hi")} </div>
      <div> {React.string("Hi")} </div>
      <div> {React.string("Hi")} </div>
      <div> {React.string("Hi")} </div>
    </div>;
  };
};

switch (ReactDOM.querySelector("#root")) {
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
| Some(element) =>
  let root = ReactDOM.Client.createRoot(element);
  ReactDOM.Client.render(root, <App />);
};
