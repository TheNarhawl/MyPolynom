<template>
  <div class="app">
    <h1 class="title">MyPolynom</h1>

    <div class="content-container">
      <div class="left-section">
        <div class="ast-container" v-if="parseData">
          <AstNode :node="rootNode" />
        </div>
      </div>

      <div class="right-section">
        <div class="input-section">
          <div class="input-group">
            <h3>Polynomial:</h3>
            <textarea id="polynomial-input" v-model="polynomialInput" placeholder="Enter polynomial expression"
              rows="3"></textarea>
          </div>

          <div class="variables-section" v-if="variables.length > 0">
            <h3>Variables:</h3>
            <div class="variable-input" v-for="(varName, index) in variables" :key="index">
              <label :for="'var-' + varName">{{ varName }}:</label>
              <input :id="'var-' + varName" type="number" v-model.number="variableValues[varName]"
                :placeholder="'Value for ' + varName" step="any" />
            </div>
          </div>

          <button class="parse-button" @click="parsePolynomial" :disabled="!canParse">
            Parse
          </button>
        </div>

        <div class="result-container" v-if="parseData?.result !== undefined">
          <h3>Result:</h3>
          <div class="result-value">{{ parseData.result }}</div>
        </div>
        <div class="terms-container" v-if="parseData?.terms">
          <h3>Terms:</h3>
          <div class="terms-list">
            <div class="term-card" v-for="(term, index) in parseData.terms" :key="index">
              <!-- <div class="term-coefficient">{{ term.coefficient > 0 ? '+' : '' }}{{ term.coefficient }}</div> -->
              <div class="term-repr">{{ term.string_repr }}</div>
              <!-- <div class="term-vars" v-if="Object.keys(term.variables).length > 0">
                <div class="var-item" v-for="(power, varName) in term.variables" :key="varName">
                  {{ varName }}<sup>{{ power }}</sup>
                </div>
              </div> -->
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed, watch, onMounted } from 'vue'
import AstNode from './components/AstNode.vue'

const polynomialInput = ref('(3*x^2 + 4*y)*(2*x - 5) + 7')
const variableValues = ref({ x: 2, y: 1 })
const variables = ref(['x', 'y'])
const parseData = ref(null)

onMounted(async () => {
  await parsePolynomial()
})

watch(polynomialInput, (newValue) => {
  extractVariables(newValue)
})

const extractVariables = (polynomial) => {
  const varMatches = polynomial.match(/[a-zA-Z]+/g) || []
  const uniqueVars = [...new Set(varMatches)]
  variables.value = uniqueVars
  uniqueVars.forEach(varName => {
    if (!(varName in variableValues.value)) {
      variableValues.value[varName] = 0
    }
  })
  Object.keys(variableValues.value).forEach(key => {
    if (!uniqueVars.includes(key)) {
      delete variableValues.value[key]
    }
  })
}

const canParse = computed(() => {
  return polynomialInput.value.trim() !== '' &&
    variables.value.length > 0 &&
    Object.values(variableValues.value).every(val => val !== null && val !== undefined)
})

const rootNode = computed(() => {
  if (!parseData.value) return null
  return {
    type: 'root',
    text: 'Polynomial Root',
    children: parseData.value.parse_trace,
  }
})

const parsePolynomial = async () => {
  try {
    const response = await fetch('http://localhost:8080/evaluate', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        polynomial: polynomialInput.value.trim(),
        variables: variableValues.value,
      }),
    })
    parseData.value = await response.json()
  } catch (error) {
    console.error('Error fetching data:', error)
    alert('не парсится.')
  }
}
</script>

<style>
@import url('https://fonts.googleapis.com/css2?family=Fira+Code:wght@400;500&family=Inter:wght@400;500;600&display=swap');

* {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}

.h3 {
  font-family: 'Inter', sans-serif;
  color: #2c3e50;
}

.app {
  font-family: 'Inter', sans-serif;
  max-width: 1600px;
  margin: 0 auto;
  padding: 24px;
  min-height: 100vh;
  background: #f8f9fa;
}

.title {
  font-size: 32px;
  font-weight: 600;
  color: #2c3e50;
  margin-bottom: 24px;
  text-align: center;
}

.content-container {
  display: flex;
  justify-content: center;
  gap: 24px;
}

.left-section {
  display: flex;
  flex-direction: column;
  gap: 24px;
  width: 700px;
}

.right-section {
  width: 500px;
  display: flex;
  flex-direction: column;
  gap: 24px;
}

.ast-container {
  height: calc(100vh - 120px);
  overflow-y: auto;
  border-radius: 12px;
  background: white;
  padding: 24px;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);
  border: 1px solid #eaeaea;
}

.result-container {
  padding: 16px;
  border-radius: 12px;
  background: white;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);
  border: 1px solid #eaeaea;
}

.result-container h3 {
  color: #2c3e50;
  margin-bottom: 8px;
}

.result-value {
  font-size: 24px;
  font-weight: 600;
  font-family: 'Fira Code', monospace;
  color: #6a11cb;
  text-align: center;
}

.input-section {
  padding: 16px;
  border-radius: 12px;
  background: white;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);
  border: 1px solid #eaeaea;
  display: flex;
  flex-direction: column;
  gap: 20px;
}

.input-group {
  display: flex;
  flex-direction: column;
  gap: 8px;
}

.input-group label {
  font-weight: 500;
  color: #2c3e50;
}

textarea,
input {
  font-family: 'Inter', sans-serif;
  padding: 10px 12px;
  border: 1px solid #ddd;
  border-radius: 6px;
  font-family: 'Fira Code', monospace;
  font-size: 14px;
}

textarea {
  resize: vertical;
  min-height: 100px;
}

.variables-section {
  display: flex;
  flex-direction: column;
  gap: 12px;
}

.variables-section h3 {
  margin-bottom: 8px;
  color: #2c3e50;
}

.variable-input {
  display: flex;
  align-items: center;
  gap: 10px;
}

.variable-input label {
  min-width: 40px;
  font-weight: 500;
}

.parse-button {
  font-family: 'Inter', sans-serif;
  padding: 12px 16px;
  background: linear-gradient(135deg, #6a11cb 0%, #2575fc 100%);
  color: white;
  border: none;
  border-radius: 6px;
  font-weight: 500;
  cursor: pointer;
  transition: all 0.2s;
}

.parse-button:hover {
  transform: translateY(-2px);
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}

.parse-button:disabled {
  background: #ccc;
  cursor: not-allowed;
  transform: none;
  box-shadow: none;
}

.terms-container {
  padding: 16px;
  border-radius: 12px;
  background: white;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);
  border: 1px solid #eaeaea;
  flex-grow: 1;
}

.terms-container h3 {
  color: #2c3e50;
  margin-bottom: 12px;
}

.terms-list {
  display: flex;
  flex-wrap: wrap;
  gap: 12px;
}

.term-card {
  padding: 12px;
  border-radius: 8px;
  background: #f8f9ff;
  border: 1px solid #e0e0ff;
  display: flex;
  flex-direction: column;
  align-items: center;
  min-width: 100px;
}

.term-coefficient {
  font-weight: 600;
  color: #2575fc;
  margin-bottom: 4px;
}

.term-repr {
  font-family: 'Fira Code', monospace;
  font-size: 14px;
  margin-bottom: 6px;
}

.term-vars {
  display: flex;
  gap: 6px;
  font-size: 12px;
  color: #666;
}

.var-item {
  background: #f0f0f0;
  padding: 2px 6px;
  border-radius: 4px;
}

sup {
  font-size: 0.8em;
  vertical-align: super;
}

.ast-container::-webkit-scrollbar {
  width: 8px;
}

.ast-container::-webkit-scrollbar-track {
  background: #f4f0fa;
  border-radius: 4px;
}

.ast-container::-webkit-scrollbar-thumb {
  background: #b694d9;
  border-radius: 4px;
  border: 1px solid #f4f0fa;
}

.ast-container::-webkit-scrollbar-thumb:hover {
  background: #9f7cd5;
}

</style>