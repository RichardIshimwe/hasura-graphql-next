import { Link } from 'react-router-dom';

const Header = () =>{

   return(
    <header>
     <ul>
        <li><Link to="/">home</Link></li>
        <li><Link to="/about">about me</Link></li>
     </ul>
    </header>
   );

}

export default Header;
