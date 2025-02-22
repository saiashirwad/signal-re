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

let reducer = (state, action) =>
  switch (action) {
  | SetInput(value) => {
      ...state,
      input: value,
    }
  | AddTodo(title) => {
      todos: [
        {
          id: List.length(state.todos),
          title,
          completed: false,
        },
        ...state.todos,
      ],
      input: "",
    }
  | ToggleTodo(id) => {
      todos:
        List.map(
          todo =>
            todo.id === id
              ? {
                ...todo,
                completed: !todo.completed,
              }
              : todo,
          state.todos,
        ),
      input: state.input,
    }
  | RemoveTodo(id) => {
      todos: List.filter(todo => todo.id !== id, state.todos),
      input: state.input,
    }
  | ClearCompleted => {
      todos: List.filter(todo => !todo.completed, state.todos),
      input: state.input,
    }
  | ClearInput => {
      todos: state.todos,
      input: "",
    }
  };

module App = {
  [@react.component]
  let make = () => {
    let (state, dispatch) = React.useReducer(reducer, initialState);
    let (input, setInput) = React.useState(() => "");

    <div>
      <input
        value={state.input}
        onChange={e => {
          let value = RR.getValueFromEvent(e);
          dispatch(SetInput(value));
        }}
      />
      <Input.Input />
      <input
        value=input
        onChange={e => {
          let value = RR.getValueFromEvent(e);
          setInput(_ => value);
        }}
      />
      <button onClick={_ => dispatch(AddTodo(state.input))}>
        {React.string("Add")}
      </button>
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
