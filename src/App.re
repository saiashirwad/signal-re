let haha = "Hi";

module App = {
  [@react.component]
  let make = () => {
    <div> <h1> {React.string(haha)} </h1> </div>;
  };
};

switch (ReactDOM.querySelector("#root")) {
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
| Some(element) =>
  let root = ReactDOM.Client.createRoot(element);
  ReactDOM.Client.render(root, <App />);
};
