module Input = {
  [@react.component]
  let make = () => {
    let (input, setInput) = React.useState(() => "");

    <div>
      <input
        value=input
        onChange={e => {
          let value = React.Event.Form.target(e)##value;
          setInput(_ => value);
        }}
      />
      <p> {React.string(input)} </p>
    </div>;
  };
};

module App = {
  [@react.component]
  let make = () => {
    <div> <Input /> </div>;
  };
};

switch (ReactDOM.querySelector("#root")) {
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
| Some(element) =>
  let root = ReactDOM.Client.createRoot(element);
  ReactDOM.Client.render(root, <App />);
};
