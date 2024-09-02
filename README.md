El codigo es un CRM basico que permite la visualizacion de usuarios registrados, añadir y eliminarlos.  

Estructura Contact 

La estructura Contact define los campos básicos que representan a un contacto en el CRM. Cada contacto incluye la siguiente información: 

1. name: El nombre del contacto. 

2. email: La dirección de correo electrónico del contacto. 

3. phone: El número de teléfono del contacto. 

4. address: La dirección física del contacto. 

5. lastContactDate: La fecha y hora del último contacto, representada como un objeto de tipo time. 

Función createContact 

La función `createContact` permite crear un nuevo contacto. Recibe como parámetros el nombre, email, teléfono y dirección del contacto. También establece la fecha del último contacto al momento actual usando `std::time(nullptr)`. 

Función addContact 

La función `addContact` añade un nuevo contacto al vector `contacts`. Esta función toma como parámetros el vector de contactos y un objeto de tipo `Contact`, añadiendo este último al final del vector. 

Función showContacts 

La función `showContacts` muestra todos los contactos almacenados en el vector. Si el vector está vacío, se muestra un mensaje indicando que no hay contactos para mostrar. En caso contrario, se imprime la información de cada contacto de manera ordenada y legible, separada por líneas de guiones. 

Función findContactByName 

La función `findContactByName` busca un contacto específico en el vector de contactos según su nombre. Si encuentra un contacto con el nombre especificado, devuelve un puntero al objeto `Contact` correspondiente; de lo contrario, devuelve un puntero nulo (`nullptr`). 

Función updateContact 

La función `updateContact` permite actualizar la información de un contacto existente. Esta función modifica el email, teléfono y dirección del contacto, y actualiza la fecha del último contacto al momento actual. 

Función deleteContact 

La función `deleteContact` elimina un contacto del vector de contactos según su nombre. Utiliza la función `std::remove_if` para buscar y eliminar el contacto que coincide con el nombre proporcionado. 

Función showMenu 

La función `showMenu` muestra un menú interactivo que permite al usuario elegir entre diferentes opciones para gestionar los contactos. Las opciones incluyen añadir un nuevo contacto, mostrar todos los contactos, actualizar un contacto, eliminar un contacto o salir del programa. 

Función main 

La función `main` controla el flujo principal del programa. Crea un vector de contactos y un bucle `do-while` que mantiene el menú interactivo activo hasta que el usuario elija salir. Según la opción seleccionada por el usuario, se llaman las funciones correspondientes para añadir, mostrar, actualizar o eliminar contactos. 
