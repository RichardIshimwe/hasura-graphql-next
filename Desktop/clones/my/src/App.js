// import react, {useState} from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import Header from './components/Header';
import About from './components/About';
import Home from './components/Home';

import './css/style.css';

let App = () => {
  // const [count, setCount]=useState(0);
// const [name,setName]=useState(" ");
// const [firstName, setFirstName]=useState(" ");
// const [lastName, setLastName]=useState(" ");
// const [number, setNumber]=useState(0);
// const [secondNumber, setSecondNumber]=useState(0);
// const [result,setResult]=useState(0);


// const handleInputValue=(e)=>{
//   setFirstName(e.target.value);
 
// }
// const handleLatName=(e)=>{
//   setLastName(e.target.value)
// }
// const sum=()=>{
// const add=parseInt(number)+parseInt(secondNumber)
// console.log(add)
// setResult(add)
// }
//   const countClick =()=> {
//     setCount(count +1);
//     setName("happy")
//   };



  return (
    <div className="App">
     <Router>
     <Header />
     <Switch>
      <Route exact path='/' component={Home}/>
      <Route path='/about' component={About}/>
     {/* <Home />
     <About /> */}
     </Switch>
     </Router>
     {/* <h1>hellooo {name} you clicked {count} times</h1>
     <input value={firstName} onChange={handleInputValue}/>
     <input value={lastName} onChange={handleLatName}/>
     <input type='text' value={number} onChange={(e) => setNumber(e.target.value)}/>
     <input type='text' value={secondNumber} onChange={(e)=>setSecondNumber(e.target.value)}/>
     <p>value from input is {firstName} and {lastName} your sum is{result} </p>
     <button onClick={countClick}>click me</button>
     <button onClick={sum}>add</button> */}
    </div>
  );
}

export default App;
