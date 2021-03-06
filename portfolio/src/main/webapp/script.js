// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// window.addEventListener('scroll', () => {
//     let current = '';
    
// })

/** Fetches hello **/
async function showSkills() {
  
  const responseFromServer = await fetch('/skills');
  const jsonFromResponse = await responseFromServer.json();

  const dateContainer = document.getElementById('skills-container');
  dateContainer.innerText = jsonFromResponse[Math.floor(Math.random() * Math.floor(3))];
}
