var contentContainer = document.querySelector(".container");
var searchquery = document.querySelector("input");
var searchButton = document.querySelector(".search-bar button");
var searchBar = document.querySelector(".search-bar");
var booksContainer = document.querySelector(".books");
var searchSection = document.querySelector(".search");
var errorMessage = document.createElement("div");
var footer = document.querySelector("footer");
var countText = document.querySelector(".count");
// playing animation
function loader() {
  booksContainer.classList.add("loader");
}
window.addEventListener("load", loader);
// Creating new XMLHttpRequest
var xhr = new XMLHttpRequest();

xhr.open(
  "GET",
  "https://www.googleapis.com/books/v1/volumes?q=software+development"
);

xhr.send();

// Rendering document based on the response
xhr.onerror = function () {
  booksContainer.classList.remove("loader");
  window.removeEventListener("load", loader);
  booksContainer.innerText = "network down or invalid URL";
  booksContainer.style.fontSize = "20px";
  booksContainer.style.color = "red";
};

xhr.onload = function () {
  booksContainer.classList.remove("loader");
  window.removeEventListener("load", loader);
  renderOnDocument(JSON.parse(xhr.response));
  createFooter();
};

// rendering response on document
function renderOnDocument(books) {
  if (books.totalItems > 0) {
    booksContainer.innerText = "";
    books.items.forEach(function (book) {
      // Creating book container for each book
      var bookcontainer = document.createElement("div");
      bookcontainer.classList.add("book");
      // creating book image
      var bookImage = document.createElement("img");
      if (book.volumeInfo.imageLinks && book.volumeInfo.imageLinks.thumbnail) {
        bookImage.setAttribute(
          "src",
          `${book.volumeInfo.imageLinks.thumbnail}`
        );
      } else {
        bookImage.setAttribute("src", `./assets/noImage.jpg`);
      }
      // creating description section for book
      var descriptionSection = document.createElement("div");
      descriptionSection.classList.add("description");
      // creating book title
      var bookTitle = document.createElement("h3");

      if (book.volumeInfo && book.volumeInfo.title) {
        bookTitle.innerText = book.volumeInfo.title;
      } else {
        bookTitle.innerText = "N/A";
      }
      bookTitle.setAttribute("title", `${book.volumeInfo.title}`);
      descriptionSection.appendChild(bookTitle);
      // creating book description
      var bookdescription = document.createElement("p");
      if (book.volumeInfo && book.volumeInfo.description) {
        bookdescription.innerHTML = book.volumeInfo.description;
      } else {
        bookdescription.innerText = "N/A";
      }
      bookdescription.setAttribute("title", `${book.volumeInfo.description}`);
      descriptionSection.appendChild(bookdescription);
      // creating author name
      var authorName = document.createElement("p");
      if (book.volumeInfo && book.volumeInfo.authors) {
        authorName.innerText = "By: " + book.volumeInfo.authors;
      } else {
        authorName.innerText = "N/A";
      }

      authorName.classList.add("author");
      authorName.setAttribute("title", `${book.volumeInfo.authors}`);
      descriptionSection.appendChild(authorName);
      // view details button
      var viewDetails = document.createElement("button");
      viewDetails.classList.add("view-details");
      viewDetails.innerText = "View details";
      viewDetails.setAttribute("id", `${book.id}`);

      // Redirection with view details button
      viewDetails.addEventListener("click", function (e) {
        if (e.target.tagName === "BUTTON") {
          window.open(`book-details.html?id=${e.target.id}`);
        }
      });
      descriptionSection.appendChild(viewDetails);
      // adding all details to book container
      bookcontainer.appendChild(bookImage);
      bookcontainer.appendChild(descriptionSection);
      // adding book to books container
      booksContainer.appendChild(bookcontainer);
    });
  } else {
    booksContainer.style.height = "500px";
    booksContainer.innerText = "No match found";
    booksContainer.style.fontSize = "20px";
    booksContainer.style.color = "red";
  }
}

// handeling user input

searchButton.addEventListener("click", search);

function search() {
  if (searchquery.value.toLowerCase().trim() === "") {
    searchquery.value = "";
    booksContainer.innerText = "";
    booksContainer.style.height = "500px";
    searchBar.insertAdjacentElement("afterend", errorMessage);
    errorMessage.innerText = "Please Enter Book name first!";
    errorMessage.style.fontSize = "18px";
    errorMessage.style.color = "red";
    errorMessage.style.textAlign = "center";
    errorMessage.style.marginTop = "30px";
  } else {
    errorMessage.remove();
    var xhr = new XMLHttpRequest();

    xhr.open(
      "GET",
      `https://www.googleapis.com/books/v1/volumes?q=${searchquery.value.toLowerCase()}`
    );

    xhr.send();

    // Rendering document based on the response
    xhr.onerror = function () {
      booksContainer.classList.remove("loader");
      booksContainer.style.height = "500px";
      booksContainer.innerText = "network down or invalid URL";
      booksContainer.style.fontSize = "20px";
      booksContainer.style.color = "red";
    };
    xhr.onload = function () {
      booksContainer.classList.remove("loader");
      renderOnDocument(JSON.parse(xhr.response));
    };
  }
}
// Function to create a footer
function createFooter() {
  var footers = document.querySelectorAll("footer");
  if (footers.length > 0) {
    return;
  } else {
    var footer = document.createElement("footer");
    contentContainer.appendChild(footer);
    footer.style.display = "flex";
    footer.style.alignItems = "center";
    footer.style.justifyContent = "center";
    footer.style.gap = "20px";

    footer.innerHTML = `<span><a href="https://github.com/Genesis-o-0" target="_blank"><i class="fa-brands fa-github fa-xl" style="color: #ffffff;"></i></a></span><span><a href="www.linkedin.com/in/mohamed-lotfy007
    " target="_blank"><i class="fa-brands fa-linkedin fa-xl" style="color: #ffffff;"></i></a></span>`;
  }
}

// updating count
var queryString = window.location.search;
var urlParams = new URLSearchParams(queryString);
var count = urlParams.get("count");
countText.innerText = count;
