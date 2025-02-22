module Input = {
  [@react.component]
  let make = () => {
    let (input, setInput) = React.useState(() => "testing");

    <div>
      <input
        value=input
        onChange={e => {
          let value = React.Event.Form.target(e)##value;
          setInput(_ => value);
        }}
      />
      <div> {React.string(input)} </div>
    </div>;
  };
};
