/* 
 * Easton Children's Museum Dimmable Cooktop Burner
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

const unsigned char IN_PIN_IDX = 0;
const unsigned char OUT_PIN_IDX = 1;
const unsigned char pin_mappings[4][2] = {{A0, 3},
                                          {A1, 5}, 
                                          {A2, 6},
                                          {A3, 9}};
const unsigned char burner_count = sizeof(pin_mappings)/
                                   (sizeof(pin_mappings[0]));
                                   
void setup() {
  unsigned char i = 0;
  for (i = 0; i < burner_count; i++) {
    pinMode(pin_mappings[i][IN_PIN_IDX], INPUT);
    pinMode(pin_mappings[i][OUT_PIN_IDX], OUTPUT);
  }
}

void loop() {
  unsigned char i = 0;
  for (i = 0; i < burner_count; i++){
    unsigned int input = analogRead(pin_mappings[i][IN_PIN_IDX]);
    
    // When mapping from 1023 to 255, use a right bit shift by 2
    // instead of division by 4. Bit shift is faster than division
    analogWrite(pin_mappings[i][OUT_PIN_IDX], input >> 2);
  }
}
