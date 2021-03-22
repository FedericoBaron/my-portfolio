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


google.charts.load("current", {packages:["timeline"]});
google.charts.setOnLoadCallback(drawChart);
function drawChart() {
var container = document.getElementById('timeline');
var chart = new google.visualization.Timeline(container);
var dataTable = new google.visualization.DataTable();

dataTable.addColumn({ type: 'string', id: 'ExperienceType' });
dataTable.addColumn({ type: 'string', id: 'Name' });
dataTable.addColumn({ type: 'date', id: 'Start' });
dataTable.addColumn({ type: 'date', id: 'End' });

dataTable.addRows([
    [ 'Intern', 'Facebook', new Date(1789, 3, 30), new Date(1797, 2, 4) ],
    [ 'Intern', 'Google', new Date(1797, 2, 4),  new Date(1801, 2, 4) ],
    [ 'Intern', 'Apple',  new Date(1801, 2, 4),  new Date(1809, 2, 4) ]]);

var options = {
    // timeline: { colorByRowLabel: true, color: '#E4E6EB' },
    timeline: { 
                colorByRowLabel: true,
                rowLabelStyle: {color: '#E4E6EB' },
                barLabelStyle: {color: '#E4E6EB' } 
            },
    backgroundColor:'#121212',
    width: 700,
};

chart.draw(dataTable, options);
}